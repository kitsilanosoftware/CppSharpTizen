//
// Open Service Platform
// Copyright (c) 2013 Samsung Electronics Co., Ltd.
//
// Licensed under the Apache License, Version 2.0 (the License);
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//


/**
 * @file     FUixVisionImageRecognizer.h
 * @brief    This is the header file for the %ImageRecognizer class.
 *
 * This header file contains the declarations of the %ImageRecognizer class.
 */

#ifndef _FUIX_VISION_IMAGE_RECOGNIZER_H_
#define _FUIX_VISION_IMAGE_RECOGNIZER_H_
#include <FBaseObject.h>
#include <FBase.h>
#include <FUixVisionImageObject.h>

namespace Tizen { namespace Uix { namespace Vision
{
class ImageFeatureManager;
/**
 * @class    ImageRecognizer
 * @brief    This class provides methods to find same image objects to input image in the feature set that stores features of the reference images.
 *
 * @since    2.1
 *
 * The %ImageRecognizer class provides methods to find same image objects to input image in the feature set that stores features of the reference images.
 *           This class also provide methods to calculate the 2D position and 3D pose transform matrix of the recognized image objects.
 *
 * The following example demonstrates how to use the %ImageRecognizer class.
 *
 * @code
 * #include <FBase.h>
 * #include <FUix.h>
 * #include <FGraphics.h>
 * #include <FIo.h>
 * #include <FMedia.h>
 * 
 * using namespace Tizen::Base;
 * using namespace Tizen::Media;
 * using namespace Tizen::Graphics;
 * using namespace Tizen::Io;
 * using namespace Tizen::Uix::Vision;
 * class MyClass
 * 	: ICameraEventListener
 * {
 * public:
 * 	MyClass();
 * 	~MyClass();
 * 	result Initialize(void);
 * 
 * 	// Called when camera auto focus occurred
 * 	void OnCameraAutoFocused(bool completeCondition);
 * 	// Called when camera preview occurred
 * 	void OnCameraPreviewed(Tizen::Base::ByteBuffer& previewedData, result r);
 * 	// Called when camera captured image
 * 	void OnCameraCaptured(Tizen::Base::ByteBuffer& capturedData, result r);
 * 	// Called when camera error occurred
 * 	void OnCameraErrorOccurred(Tizen::Media::CameraErrorReason r);
 * 
 * private:
 * 	ImageRecognizer*	__pImageRecognizer;
 * 	ImageFeatureManager*	__pFeatureManager;
 * };
 * 
 * result
 * MyClass::Initialize(void)
 * {
 * 	result r;
 * 
 * 	// Creates and initializes a recognition engine
 * 	__pImageRecognizer = new Tizen::Uix::Vision::ImageRecognizer();
 * 	r = __pImageRecognizer->Construct();
 *
 * 	// Creates an initialized ImageFeatureManager
 * 	__pFeatureManager  = new Tizen::Uix::Vision::ImageFeatureManager();
 * 	r = __pFeatureManager->Construct();
 * 
 * 	// Loads a feature set
 * 	r = __pFeatureManager->Load("/opt/usr/media/Images/testFeatureSet.xdb");
 * 
 * 	// Configures the recognition engine
 * 	r =__pImageRecognizer->SetFeatureManager(*__pFeatureManager);
 *
 *   // Sets the image size to be same as the camera preview size
 * 	r = __pImageRecognizer->SetImageSize(640, 480);
 * 
 * 	__pImageRecognizer->SetMultiTrackingEnabled(false);
 * 
 * 	return r;
 * }
 * 
 * // We suppose camera to be initialized with Tizen::Graphics::PIXEL_FORMAT_YCbCr420_PLANAR format
 * void
 * MyClass::OnCameraPreviewed(Tizen::Base::ByteBuffer& previewedData, result r)
 * {
 * 	// Processes the camera image
 * 	__pImageRecognizer->ProcessImage(previewedData);
 * 
 * 	// Loops through all recognized images
 * 	for (int i = 0; i < __pImageRecognizer->GetRecognizedObjectCount(); i++)
 * 	{
 * 		const ImageObject *o = __pImageRecognizer->GetRecognizedObject(i);
 * 		int featId = o->GetFeatureId();
 * 	}
 * }
 *
 * @endcode
 */

class _OSP_EXPORT_ ImageRecognizer
    : public Tizen::Base::Object
{
public:

    /**
     * This is the default constructor for this class. @n
     * The object is not fully constructed after this constructor is called. @n
     * For full construction, the Construct() method must be called right after calling this constructor.
     *
     * @since    2.1
     */
    ImageRecognizer(void);

    /**
     * This is the destructor for this class. @n
     * The resources are deallocated by this method.
     * This destructor overrides Tizen::Base::Object::~Object().
     *
     * @since    2.1
     */
    ~ImageRecognizer(void);

    /**
     * Initializes this instance of %ImageRecognizer. @n
     * Every application must call %Construct() before calling any other methods of %ImageRecognizer.
     *
     * @since        2.1
     *
     * @feature      %http://tizen.org/feature/vision.image_recognition
     *
     * @exception    E_SUCCESS          The method is successful.
     * @exception    E_UNSUPPORTED_OPERATION   The Emulator or target device does not support the required feature. 
     * For more information, see <a href="../org.tizen.gettingstarted/html/tizen_overview/application_filtering.htm">Application Filtering</a>.
     * @remarks      Before calling this method, check whether the feature is supported by 
	 *			Tizen::System::SystemInfo::GetValue(const Tizen::Base::String&, bool&).
     */
    result Construct(void);

    /**
     * Enables single or multiple tracking mode.
     *
     * @since        2.1
	 *
     * @param[in]    enable        Enable multiple tracking mode on @c true, default is single tracking mode
     *
     * @remarks      
     *			- In single tracking mode, only one image is recognized in the screen at once.
     *			- In multiple tracking mode, multiple images (maximum 3) can be recognized and tracked simultaneously.
     */
    void SetMultiTrackingEnabled(bool enable);

    /**
     * Sets the width and height of an input image.
     *
     * @since        2.1
     *
     * @return       An error code
     *
     * @param[in]    width            The width of the input image
     * @param[in]    height           The height of the input image
     *
     * @exception    E_SUCCESS        The method is successful.
     * @exception    E_INVALID_ARG    A specified input parameter is invalid.
     */
    result SetImageSize(int width, int height);

    /**
     * Sets the ImageFeatureManager instance for initialization.
     *
     * @since       2.1
     * @pre         ImageFeatureManager should be initialized by loading a feature set file using the ImageFeatureManager::Load() method.
     *
     * @return      An error code
     * @param[in]   imageFeatureManager      The ImageFeatureManager instance managing image feature set to use for recognition
     * @exception   E_SUCCESS                The method is successful.
     * @exception   E_INVALID_ARG            An input ImageFeatureManager is invalid.
     *
     * @remarks     ImageFeatureManager should be initialized by loading a feature set file.
     */
    result SetFeatureManager(ImageFeatureManager& imageFeatureManager);

    /**
     * Gets a count of the recognized image object.
     *
     * @since        2.1
     *
     * @return       A count of the recognized image object
     *
     * @remarks      The recognized object has index value from @c 0 to (count of the recognized image objects - 1)
     * @see          GetRecognizedObject(int)
     */
    int GetRecognizedObjectCount(void);

    /**
     * Gets the recognized image object to get information.
     *
     * @since        2.1
     *
     * @return       A pointer to ImageObject that includes all information about the recognized image object
     * @param[in]    index             The index of the recognized image object @n
     *                                 Valid range of this parameter is @c 0 to (count of the recognized image objects - 1).
     * @exception    E_SUCCESS         The method is successful.
     *
     * @see          GetRecognizedObjectCount()
     */
    const ImageObject* GetRecognizedObject(int index) const;

    /**
     * Processes an input image for recognition.
     *
     * @since        2.1
     *
     * @return       An error code
     *
     * @param[in]    imageBuffer        The input image buffer @n
     *                                  It must be allocated outside and have size of (width*height) set by SetImageSize().
     * @exception    E_SUCCESS          The method is successful.
     * @exception    E_INVALID_ARG      The specified @c imageBuffer is not allocated or the size of @c imageBuffer is not equal to the input image size set by SetImageSize().
     * @exception    E_OUT_OF_MEMORY    The memory is insufficient.
     * @see          SetImageSize(int, int)
     */
    result ProcessImage(const Tizen::Base::ByteBuffer& imageBuffer);

private:
    /**
     * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
     */
    ImageRecognizer(const ImageRecognizer&);

    /**
     * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
     */
    ImageRecognizer& operator=(const ImageRecognizer&);

private:
    class _ImageRecognizerImpl* __pImageRecognizerImpl; ///< implementation bridge
    friend class _ImageRecognizerImpl;
};

} } } //Tizen::Uix::Vision

#endif // _FUIX_VISION_IMAGE_RECOGNIZER_H_
